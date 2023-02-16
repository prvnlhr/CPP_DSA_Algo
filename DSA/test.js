var foo = function (name) {
    this.myName = name;
    this.tellMyName = function () {
        console.log(this.myName);
    }
}

var fooObj1 = new foo('James');
fooObj1.tellMyName(); // will print James
var fooObj2 = new foo('Mike');
fooObj2.tellMyName(); // will print Mike


var foo = function (name) {
    this.myName = name;
}

foo.prototype.tellMyName = function () {
    console.log(this.myName);
}

var fooObj1 = new foo('James');
fooObj1.tellMyName(); // will print James
var fooObj2 = new foo('Mike');
fooObj2.tellMyName(); // will print Mike
