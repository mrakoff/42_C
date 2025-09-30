function GetCookie() {
    var cookies = document.cookie.split("; ");
    for (var i = 0; i < cookies.length; i++) {
        var parts = cookies[i].split("=");
        if (parts[0] === "todos") {
            return parts[1];
        }
    }
    return null;
}
function Savetodos() {
    var todos = [];
    var list = document.getElementById("ft_list").children;
    for (var i = 0; i < list.length; i++) {
        todos.push(list[i].textContent);
    }
    document.cookie = "todos= " + encodeURIComponent(JSON.stringify(todos)) + ";path=/";
}
function  createToDoElement(text) {
    var ToDoDiv = document.createElement("div");
    ToDoDiv.textContent = text;
    ToDoDiv.addEventListener("click", function() {
        if (confirm("Do you want to delete the To Do?")) {
            ToDoDiv.remove();
            Savetodos();
        }
    });
    document.getElementById("ft_list").insertBefore(ToDoDiv, document.getElementById("ft_list").firstChild)
    Savetodos();
}
function click() {
    document.getElementById("newToDo").addEventListener("click", function() {
        var newToDoText = prompt("Enter a new To Do: ");
        if (newToDoText !== null && newToDoText.trim() !== "") {
            createToDoElement(newToDoText.trim());
        }
    });
}
function Loadtodos() {
    var todostr = GetCookie();
    if (todostr) {
        var todos = JSON.parse(decodeURIComponent(todostr));
        for (var i = 0; i < todos.length; i++) {
            createToDoElement(todos[i]);
        }
    }
}
window.onload = function() {
    click();
    Loadtodos();
}
