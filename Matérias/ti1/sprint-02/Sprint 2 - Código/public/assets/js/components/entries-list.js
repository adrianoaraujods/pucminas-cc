import category from "../controllers/category.js";
import entry from "../controllers/entry.js";
import { insertMissingRecurringEntries } from "../controllers/recurrent.js";

import { ICONS_NAMES } from "../lib/constants.js";
import { formatDateToInput, toMoney } from "../lib/util.js";
import { updateMonthTotal } from "./month-total.js";

import { updateCategorySelect } from "./select-category.js";

export async function updateEntriesList(entries) {
  if (!entries) {
    await insertMissingRecurringEntries();

    entries = await entry.getAllFromUser();
  }

  const today = new Date();

  updateMonthTotal("current-month");
  updateMonthTotal("previous-month", today.getMonth() - 1, today.getFullYear());

  const entriesList = document.querySelector(".entries-list");
  entriesList.innerHTML = "";

  const editEntryForm = document.getElementById("edit-entry-form");
  const editEntryPopup = document.getElementById("edit-entry-popup");

  const userCategories = await category.getAllFromUser();

  entries.forEach(({ date, id, type, categoryId, value, label }) => {
    const dayListMissing = !document.getElementById(
      `entries-list__day-${date}`
    );

    if (dayListMissing) {
      entriesList.insertAdjacentHTML(
        "beforeend",
        `
        <li class="entries-list__item">
          <h3>${new Date(date).toLocaleDateString("pt-BR", {
            day: "numeric",
            month: "long",
            year: "numeric",
          })}</h3>
          <ul
            class="entries-list__day"
            id="entries-list__day-${date}"
          ></ul>
        </li>
        `
      );
    }

    const parentElement = document.getElementById(`entries-list__day-${date}`);

    const isIncome = type === "income";

    const category = userCategories.filter((category) => {
      return category.id === categoryId;
    })[0];

    parentElement.insertAdjacentHTML(
      "beforeend",
      `
    <li class="entries-list__day__item">
      ${
        category && category.icon && ICONS_NAMES.includes(category.icon)
          ? `<img
              class="entries-list__day__item__icon"
              src="./assets/img/icon/selectable/${category.icon}.svg"
              alt="icon"
            />`
          : "<div></div>"
      }

      <span class="entries-list__day__item__value${
        isIncome
          ? " entries-list__day__item__value--income"
          : " entries-list__day__item__value--expense"
      }">${isIncome ? "" : "-"}R$ ${toMoney(value)}</span>

      <span class="entries-list__day__item__title">${label}</span>

      <button
        class="entries-list__day__item__button entries-list__day__item__button--edit"
        id="button-edit-entry-${id}"
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
          <path
            d="M21.174 6.812a1 1 0 0 0-3.986-3.987L3.842 16.174a2 2 0 0 0-.5.83l-1.321 4.352a.5.5 0 0 0 .623.622l4.353-1.32a2 2 0 0 0 .83-.497z"
          />
          <path d="m15 5 4 4" />
        </svg>
      </button>
      <button
        class="entries-list__day__item__button entries-list__day__item__button--delete"
        id="button-delete-entry-${id}"
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

    const editButton = document.getElementById(`button-edit-entry-${id}`);
    const deleteButton = document.getElementById(`button-delete-entry-${id}`);

    editButton.addEventListener("click", async () => {
      editEntryForm.setAttribute("data-entry-id", id);

      document.getElementById("edit-entry-form--label").value = label;
      document.getElementById("edit-entry-form--date").value =
        formatDateToInput(new Date(date));
      document.getElementById("edit-entry-form--value").value = value;

      await updateCategorySelect("edit-entry-form--category", type);

      document.getElementById("edit-entry-form--category").value = categoryId;

      if (type === "income") {
        document.getElementById("edit-entry-form--income").checked = true;
      } else {
        document.getElementById("edit-entry-form--expense").checked = true;
      }

      editEntryPopup.showModal();
    });

    deleteButton.addEventListener("click", async () => {
      const deleted = await entry.delete(id);

      if (!deleted) {
        alert("Erro ao deletar registro.");
        return;
      }

      updateEntriesList();
    });
  });
}
