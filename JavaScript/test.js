const obj = new Object();
obj.a = 123;
obj.b = 'hello';
obj[Symbol('foo')] = '123';
let sym = Symbol('foo');
obj[sym] = "str";

let symbolArr = Object.getOwnPropertySymbols(obj);

console.log(symbolArr);

console.log(Object.getOwnPropertyNames(obj));

console.log(obj.a);
console.log(obj.c);

let foo = {unique_prop: 1}, bar = {unique_prop: 2}, object = {};
object[foo] = 'value'
console.log(foo.toString());
console.log(bar.toString());
console.log(object[bar])

object;

const obj2 = {};
obj2[' '] = 1234;
obj2['123'] = 1234;
obj2['$&#(!(@'] = "wow";
obj2;

function Car(make, model, year) {
    this.make = make;
    this.model = model;
    this.year = year;
  }
  
const myCar = new Car('Eagle', 'Talon TSi', 1993);
  
console.log(myCar.make);
console.log(myCar[0]);

const myCar2 = {
    0: 'make',
    5: 'model',
    'faewf@$&&%#': 'year'
}

console.log(myCar2['faewf@$&&%#']);
