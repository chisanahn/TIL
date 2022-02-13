// 'use strict';

function Animal() { }

Animal.prototype.speak = function() {
  return this;
}

Animal.eat = () => {
  return this;
}

let obj = new Animal();
let speak = obj.speak;
speak(); // global object (in non–strict mode)

console.log(Animal.eat())

let eat = Animal.eat;
console.log(eat()); // global object (in non-strict mode)

const func = function () {
	return this;
}

const func2 = () => {
	return this;
}

console.log(func());
console.log(func2());