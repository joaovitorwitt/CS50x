// show password feature

// make sure that all the content in the page is loaded before executing any javascript
window.onload = function() {
    // checkbox and input field from login from
    loginCheckbox = document.querySelector(".show-password");
    loginPassword = document.querySelector("#password");

    // when the checkbox clicked, we change the input to type text to show the content
    loginCheckbox.addEventListener("click", (e) => {
        if (loginPassword.type === "password") {
            loginPassword.type = "text";
        } else {
            loginPassword.type = "password";
        }
    })

    // checkbox and input fields from register page
    registerCheckbox = document.querySelector(".show-password");
    registerPassword = document.querySelector("#register-password");
    confirmPassword = document.querySelector("#confirm-password");

    // same logic as the login page
    registerCheckbox.addEventListener("click", (e) => {
        if (registerPassword.type === "password" && confirmPassword.type === "password") {
            registerPassword.type = "text";
            confirmPassword.type = "text";
        } else {
            registerPassword.type = "password";
            confirmPassword.type = "password";
        }
    })
};

