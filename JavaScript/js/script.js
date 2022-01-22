let button = document.getElementById("changeBackground");

let count = 0;
let color;
button.addEventListener("click", () => {
	count++;
	count %= 2;
	if (count == 0) color = "white";
	else color = "fuchsia";
	document.body.style.backgroundColor = color;
});
