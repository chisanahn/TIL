let mycar = {make: 'Honda', model: 'Accord', year: 1998};

delete mycar.year;
'year' in mycar; // false

mycar.make = undefined;
'make' in mycar;   // true