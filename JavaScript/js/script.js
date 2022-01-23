const app = document.getElementById('root');

const logo = document.createElement('img');
logo.src = 'https://github.com/taniarascia/sandbox/blob/master/ghibli/logo.png?raw=true';

const container = document.createElement('div');
container.setAttribute('class', 'container');

app.appendChild(logo);
app.appendChild(container);

// let request = new XMLHttpRequest();
// request.open('GET', 'https://ghibliapi.herokuapp.com/films', true);
// request.onload = function () {
//   const data = JSON.parse(this.response);
//   if (request.status == 200)
//     data.forEach(movie => console.log(movie.title));
//   else
//     console.log('error');
// }
// request.send();

async function getData() {
	const response = await fetch("https://ghibliapi.herokuapp.com/films");
  const data = await response.json();
  if (response.status == 200)
    data.forEach(movie => {
      const card = document.createElement('div');
      card.setAttribute('class', 'card');

      const h1 = document.createElement('h1');
      h1.textContent = movie.title;

      const p = document.createElement('p');
      p.textContent = `${movie.description.substring(0, 300)}...`;

      container.appendChild(card);
      card.appendChild(h1);      
      card.appendChild(p);      
    });
  else
    console.log('error');
}
getData();

