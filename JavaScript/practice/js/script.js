const spinner = document.querySelector("div");
const degreeLabel = document.querySelector("p.degree");
let prevDegree = 0;
let curDegree = 0;
let startTime = null;
let rAf;

function draw(timestamp) {
	if (!startTime) {
		startTime = timestamp;
	}

	curDegree = (prevDegree + (timestamp - startTime) / 30) % 360;
	degreeLabel.textContent = `${curDegree.toFixed(0)}`;

	spinner.style.transform = `rotate(${curDegree}deg)`;

	rAf = requestAnimationFrame(draw);
}

const body = document.body;

let spinnerIsRun = false;

body.addEventListener('click', () => {
	if (spinnerIsRun) {
		cancelAnimationFrame(rAf);
		spinnerIsRun = false;
		prevDegree = curDegree;
	}
	else {
		startTime = null;
		draw();
		spinnerIsRun = true;
	}
});