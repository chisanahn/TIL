function Person(name, age) {
    this.name = name;
    this.age = age;
}

Person.prototype.introduce = function () {
    return `Hi my name is ${this.name}!`;
}

function Worker (name, age, job) {
    Person.call(this, name, age);
    this.job = job;
}

Worker.prototype.whatIsYourJob = function () {
    return `My job is a ${this.job}`;
}

function Worker2 (name, age, job) {
    Person.call(this, name, age);
    this.job = job;
}

Worker2.prototype.whatIsYourJob = function () {
    return `My job is a ${this.job}`;
}

Object.setPrototypeOf(Worker.prototype, Person.prototype);
// Worker2.prototype.__proto__ = Person.prototype;
Worker2.prototype.__proto__ = Object.create(Person.prototype);

let joshua = new Person('joshua', 23);
let kenny = new Worker("kenny", 31, "programmer");

console.log(Worker.prototype.__proto__ === Worker2.prototype.__proto__);
console.log(Worker2 instanceof Person)

Worker2.prototype.__proto__.test = function () {
    return "test";
}

console.log(Person.prototype);

Person.prototype.test2 = function() {
    return "test2";
}

let kenny2 = new Worker2("kenny", 31, "programmer");
console.log(kenny2.introduce());
console.log(kenny2.__proto__.__proto__.constructor === Person.prototype.constructor);
