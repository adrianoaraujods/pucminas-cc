import { auth } from "./auth.js";
import { ICONS_NAMES } from "./icons-selector.js";

const createCategoryForm = document.getElementById("create-category-form");
const editCategoryForm = document.getElementById("edit-category-form");
const editCategoryPopup = document.getElementById("edit-category-popup");
const user = auth();

let userCategories = [];

async function updateUserCategoriesList() {
  userCategories = await getUserCategories(user.id);

  const categoriesList = document.getElementById("user-categories");

  categoriesList.innerHTML = "";

  for (const { id, label, icon, type } of userCategories) {
    categoriesList.insertAdjacentHTML(
      "beforeend",
      `
      <li class="popup__content__list__item popup__content__list__item--${
        type === "income" ? "success" : "destructive"
      }">
        ${
          !icon || icon === "none" || !ICONS_NAMES.includes(icon)
            ? "<div></div>"
            : `
              <img
                class="popup__content__list__item__icon"
                src="assets/img/icon/selectable/${icon}.svg"
                alt="category ${label} icon"
              />
        `
        }
        <p class="popup__content__list__item__title">${label}</p>
        <button
          id="button-edit-category-${id}"
          class="popup__content__list__item__edit"
          type="button"
        >
          <svg
            xmlns="http://www.w3.org/2000/svg"
            width="24"
            height="24"
            viewBox="0 0 24 24"
            fill="none"
            stroke="currentColor"
            stroke-width="2"
            stroke-linecap="round"
            stroke-linejoin="round"
            class="lucide lucide-pencil"
          >
            <path
              d="M21.174 6.812a1 1 0 0 0-3.986-3.987L3.842 16.174a2 2 0 0 0-.5.83l-1.321 4.352a.5.5 0 0 0 .623.622l4.353-1.32a2 2 0 0 0 .83-.497z"
            />
            <path d="m15 5 4 4" />
          </svg>
        </button>
        <button
          id="button-delete-category-${id}"
          class="popup__content__list__item__delete"
          type="button"
        >
          <svg
            width="24"
            height="24"
            viewBox="0 0 24 24"
            fill="none"
            stroke="currentColor"
            stroke-width="2"
            stroke-linecap="round"
            stroke-linejoin="round"
          >
            <path d="M3 6h18" />
            <path d="M19 6v14c0 1-1 2-2 2H7c-1 0-2-1-2-2V6" />
            <path d="M8 6V4c0-1 1-2 2-2h4c1 0 2 1 2 2v2" />
            <line x1="10" x2="10" y1="11" y2="17" />
            <line x1="14" x2="14" y1="11" y2="17" />
          </svg>
        </button>
      </li>
      `
    );

    document
      .getElementById(`button-delete-category-${id}`)
      .addEventListener("click", async () => {
        if (
          confirm(
            `Você tem certeza que quer deletar a categoria: "${label}"? Essa ação não pode ser desfeita!`
          )
        ) {
          const success = await deleteCategoryById(id);

          if (success) {
            updateUserCategoriesList();
          } else {
            alert("Não foi possível deletar a categoria, tente novamente.");
          }
        }
      });

    document
      .getElementById(`button-edit-category-${id}`)
      .addEventListener("click", async () => {
        editCategoryForm.setAttribute("data-category-id", id);

        document.getElementById("edit-category-form--label").value = label;

        if (type === "income") {
          document.getElementById("edit-category-form--income").checked = true;
        } else {
          document.getElementById("edit-category-form--expense").checked = true;
        }

        if (icon && icon !== "none" && ICONS_NAMES.includes(icon)) {
          document.getElementById(`edit-category-icon--${icon}`).checked = true;
        }
        document.querySelector(".edit-category-form ");

        editCategoryPopup.showModal();
      });
  }
}

export function createCategoryEvents() {
  createCategoryForm.addEventListener("submit", async (event) => {
    event.preventDefault();

    if (!user.id) {
      alert("Não Autorizado");
      return;
    }

    const label = document.getElementById("create-category-form--label").value;

    if (label === "") {
      alert("Forneça um título");
      return;
    }

    const type = document.getElementById("create-category-form--income").checked
      ? "income"
      : "expense";

    let icon = document
      .querySelector(
        "#create-category-form .form__field__icons__item__input:checked"
      )
      .getAttribute("data-icon-name");

    if (icon === "none") icon = undefined;

    const newCategory = await createCategory({
      ownerId: user.id,
      label,
      type,
      icon,
    });

    if (!newCategory) {
      alert("Erro interno do servidor, tente novamente");
      return;
    }

    updateUserCategoriesList();

    document.getElementById("create-category-popup").close();
    createCategoryForm.reset();
  });

  editCategoryForm.addEventListener("submit", async (event) => {
    event.preventDefault();

    const id = editCategoryForm.getAttribute("data-category-id");

    if (!id || id === "") {
      alert("Houve algum erro, tente novamente");
      editCategoryPopup.close();
      return;
    }

    const categoryId = parseInt(id);

    if (!user.id) {
      alert("Não Autorizado");
      return;
    }

    const label = document.getElementById("edit-category-form--label").value;

    if (label === "") {
      alert("Forneça um título");
      return;
    }

    const type = document.getElementById("edit-category-form--income").checked
      ? "income"
      : "expense";

    let icon = document
      .querySelector(
        "#edit-category-form .form__field__icons__item__input:checked"
      )
      .getAttribute("data-icon-name");

    if (icon === "none") icon = undefined;

    const updatedCategory = await updateCategoryById({
      categoryId,
      icon,
      label,
      type,
    });

    if (!updatedCategory) {
      alert("Erro interno do servidor, tente novamente");
      return;
    }

    updateUserCategoriesList();

    editCategoryPopup.close();
    editCategoryForm.reset();
  });

  updateUserCategoriesList();
}

export async function createCategory({ label, type, ownerId, icon }) {
  if (!label || !type || !ownerId) {
    console.error("Erro ao criar categoria, falta dados.");

    return null;
  }

  if (!(type === "income" || type === "expense")) {
    console.error(`Erro ao criar categoria, tipo: "${type}" é inválido.`);

    return null;
  }

  const user = await fetch(`/users/${ownerId}`);

  if (!user) {
    console.error("Erro ao criar categoria, usuário não existe.");

    return null;
  }

  const time = new Date().getTime();

  const data = await fetch("/categories", {
    method: "POST",
    headers: { "Content-Type": "application/json" },
    body: JSON.stringify({
      ownerId,
      label,
      type,
      icon,
      createdAt: time,
      updatedAt: time,
    }),
  });

  if (!data) {
    console.error("Erro ao criar categoria.");

    return null;
  }

  const newCategory = data.json();

  return newCategory;
}

export async function getUserCategories(userId) {
  const res = await fetch("/categories");

  if (!res.ok) {
    console.error("Erro ao carregar as categorias");
    return null;
  }

  const data = await res.json();

  const userCategories = data.filter(({ ownerId }) => ownerId === userId);

  return userCategories;
}

export async function updateCategoryById({ categoryId, label, icon, type }) {
  const updatedAt = new Date().getTime();

  const res = await fetch(`/categories/${categoryId}`, {
    method: "PATCH",
    headers: { "Content-Type": "application/json" },
    body: JSON.stringify({ label, icon, type, updatedAt }),
  });

  if (!res.ok) {
    console.error("Erro ao atualizar a categoria.");

    return null;
  }

  const updatedCategory = await res.json();

  return updatedCategory;
}

export async function deleteCategoryById(categoryId) {
  const res = await fetch(`/categories/${categoryId}`, {
    method: "DELETE",
  });

  if (!res.ok) {
    console.error("Erro ao excluir a categoria.");
  }

  return res.ok;
}
