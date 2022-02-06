const propertyName = 'abc';

const CustomObj = {
	a: 1,
	b: 2,

	constructor: function (a, b) {
		this.a = a;
		this.b = b;
	},

	[propertyName] () {
		return this.a + this.b;
	}
}

CustomObj;
