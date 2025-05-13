import { auth, logout } from "./auth.js";
import { createCategoryEvents } from "./categories.js";
import { createIconsSelector } from "./icons-selector.js";
import { createPopupEvents } from "./popup.js";

const user = auth();

if (!auth()) window.location.replace("./login.html");

const logoutButton = document.getElementById("logout-button");

logoutButton.addEventListener("click", (event) => {
  event.preventDefault;

  logout();
});

createCategoryEvents();

createPopupEvents();

createIconsSelector();
