//-> https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array

//|>  1. Creating a static array

const arr1 = [1, 2, 3, 4, 5];
console.log(arr1);

//|> 1.2 Creating an array of length n and initialize with some values : `new` , `fill`

let n = 5;
const arr2 = new Array(n);
console.log(arr2); // [<5 empty items>]

arr2.fill(0);
console.log(arr2); // [0,0,0,0,0];

//OR
const arr3 = new Array(n).fill(0);
console.log(arr3); // [0,0,0,0,0];

// ------------------------------------------------------------------------

//|> 3. Accessing elements of arr

const arr4 = [5, 7, 6, 8, 2, 6];
console.log(arr4[3]); // 8
console.log(arr4[10]); // undefined

//|> 3.1 Accessing in 2D array
const twoDarr = [5, 2, 4, 6, [1, 2, 5]];
console.log(twoDarr[4]); // [1,2,5]
console.log(twoDarr[4][2]); // 5
// ------------------------------------------------------------------------

//|> 4. Length of array : `length`

const len = arr4.length;
console.log(len); // 6

// -----------------------------------------------------------------------

//|> 5. Modifying arr elements

const arr5 = [1, 2, 3, 4];
console.log(arr5); // 1 2 3 4

arr5[1] = 8;
console.log(arr5); // 1 8 3 4

//|> 5.1 Modifying element not present or index not present

arr5[7] = 24;
console.log(arr5); // [ 1, 8, 3, 4, <3 empty items>, 24 ]

console.log(arr5.length); // 8

console.log(Object.keys(arr5));

//|> when we try to print array indices
console.log(Object.keys(arr5)); // [ '0', '1', '2', '3', '7' ]

console.log(arr5[4]); // undefined

//|> decresing the length of arr

arr5.length = 3;
console.log(arr5); // [1, 8, 3]
console.log(arr5.length); // 3

// ---------------------------------------------------------------------------

//|> 6. Find the element at given index

const arr6 = [5, 12, 8, 130, 44];
const index = 3;
console.log(`Element at index ${index} -> ${arr6[index]}`); // Element at index 3 -> 130

// ---------------------------------------------------------------------------------

//|> 7. Using at to find element at index: `at`

const cart = ["apple", "banana", "pear"];

let eleAtIndex = cart.at(2);
console.log(eleAtIndex); // pear

//|> 7.1 `at` also works with neagative indexing

console.log(cart.at(-2)); // banana

// IMP: note that we use `()` with at

// -----------------------------------------------------------------------------------

//|> 8. merging two or more arrays : `concat()` : Returns new array

const array1 = ["a", "b", "c"];
const array2 = ["d", "e", "f"];

const array3 = array1.concat(array2);
console.log(array3); // [ 'a', 'b', 'c', 'd', 'e', 'f' ]

//|> 8.1 merging more then two arrays

const num1 = [1, 2, 3];
const num2 = [4, 5, 6];
const num3 = [7, 8, 9];

const numbers = num1.concat(num2, num3);

console.log(numbers); // [1,2,3,4,5,6,7,8,9];

//|> 8.2 merging values to array

const letters = ["a", "b", "c"];

const aplaNumeric = letters.concat(1, [8, 9]);
console.log(aplaNumeric); // ['a', 'b', 'c', 1, 2, 3]

//  -------------------------------------------------------------------------------

//|> 9. Copy element from one index to another : `copyWithin`

copyWithin(target, start);
copyWithin(target, start, end);

console.log([1, 2, 3, 4, 5].copyWithin(0, 3));
// [4, 5, 3, 4, 5]

console.log([1, 2, 3, 4, 5].copyWithin(0, 3, 4));
// [4, 2, 3, 4, 5]

console.log([1, 2, 3, 4, 5].copyWithin(-2, -3, -1));
// [1, 2, 3, 3, 4]

// ----------------------------------------------------------------------------------

//|> 10. Getting key value pair from array : `entries`

const a = ["a", "b", "c"];

const arrayEntries = a.entries();

for (const pair of arrayEntries) {
  console.log(pair);
}

// [0, 'a']
// [1, 'b']
// [2, 'c']

// OR
for (const [key, val] of arrayEntries) {
  console.log(key, val);
}

// [0, 'a']
// [1, 'b']
// [2, 'c']

// --------------------------------------------------------------------------------------------

//|> 11. `every`

/*

The every() method of Array instances tests whether all elements in
the array pass the test implemented by the provided function.
It returns a Boolean value.

The every() method is an iterative method. It calls a provided callbackFn 
function once for each element in an array, until the callbackFn returns a 
falsy value. If such an element is found, every() immediately returns false 
and stops iterating through the array. Otherwise, if callbackFn returns a 
truthy value for all elements, every() returns true.

*/

const isBelowThreshold = (currentValue) => currentValue < 40;

const array11 = [1, 30, 39, 29, 10, 13];

console.log(array1.every(isBelowThreshold));

function isBigEnough(element, index, array) {
  return element >= 10;
}

[12, 5, 8, 130, 44].every(isBigEnough); // false
[12, 54, 18, 130, 44].every(isBigEnough); // true

// --------------------------------------------------------------------------------------------

//|> 12. `fill()`

const array12 = [1, 2, 3, 4];

// Fill with 0 from position 2 until position 4
console.log(array1.fill(0, 2, 4));
// Expected output: Array [1, 2, 0, 0]

// Fill with 5 from position 1
console.log(array1.fill(5, 1));
// Expected output: Array [1, 5, 5, 5]

console.log(array1.fill(6));
// Expected output: Array [6, 6, 6, 6]

// ------------------------------------------------------------------------

// |> 13.`filter`  -> returns new array with truthy filter values

const words = ["spray", "elite", "exuberant", "destruction", "present"];

const result = words.filter((word) => word.length > 6);

console.log(result); // ["exuberant", "destruction", "present"]
console.log(words); // ['spray', 'elite', 'exuberant', 'destruction', 'present']

// ------------------------------------------------------------------------
//|>14.  `find` -> finds first matching element and returns it else undefined

const array14 = [5, 12, 8, 130, 44];

const found = array14.find((element) => element > 10);

console.log(found); // 12

const inventory = [
  { name: "apples", quantity: 2 },
  { name: "bananas", quantity: 0 },
  { name: "cherries", quantity: 5 },
];

function isCherries(fruit) {
  return fruit.name === "cherries";
}

console.log(inventory.find(isCherries)); //  { name: "cherries", quantity: 5 }

//---------------------------------------------------------------------------

//|> 15. `findIndex` returns the index of the first element in an array that satisfies the provided testing function. If no elements satisfy the testing function, -1 is returned.

const array15 = [5, 12, 8, 130, 44];

const isLargeNumber = (element) => element > 13;

console.log(array15.findIndex(isLargeNumber)); // 3

/*

!IMP: If you need to find:

|> the first element that matches, use `find()`.
|> the index of the last matching element in the array, use `findLastIndex()`.
|> the index of a value, use `indexOf()`. (It's similar to findIndex(), but checks each element for equality with the value instead of using a testing function.)
|> whether a value exists in an array, use `includes()`. Again, it checks each element for equality with the value instead of using a testing function.
|> if any element satisfies the provided testing function, use `some()`.

*/

//|> 16.  `sort`
const arr16 = [3, 7, 4, 1, 10, 4];

arr16.sort(arr16);
console.log(arr16);

//|> if dont want to mutate original array

const arr17 = [3, 7, 4, 1, 10, 4];

const sorted = [...arr16].sort((a, b) => a - b); // requires custom comp

console.log(sorted); // sorted array  : [ 1, 3, 4, 4, 7, 10 ]
console.log(arr17); // unchanged -> [3, 7, 4, 1, 10, 4]

// |> 17. `join`

//Ex_1.
const elements = ["Fire", "Air", "Water"];

console.log(elements.join()); // "Fire,Air,Water" -> default delimeter `,`

console.log(elements.join("")); // "FireAirWater"

console.log(elements.join("-")); // "Fire-Air-Water"

//Ex_2.
console.log([1, , 3].join()); // '1,,3'
console.log([1, undefined, 3].join()); // '1,,3'

//Ex_3.
const matrix = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9],
];

console.log(matrix.join()); // 1,2,3,4,5,6,7,8,9
console.log(matrix.join(";")); // 1,2,3;4,5,6;7,8,9

//|>18. `splice` :  delete or add elements : mutates the og array

// Ex_1.
const array18 = [1, 2, 3, 4, 5];

// Remove two elements starting from index 2
const removedElements = array.splice(2, 2); // (startIndex, countOfElementToDelete)

console.log(array); // [1, 2, 5]
console.log(removedElements); // [3, 4]

// Ex_2.
const array19 = [1, 2, 3, 4, 5];

// Add elements at index 2
array.splice(2, 0, 6, 7); // (startIndex, countOfElementToDelete, ..elements to add)

console.log(array); // [1, 2, 6, 7, 3, 4, 5]

//Ex_3.
const array20 = [1, 2, 3, 4, 5];

// Replace two elements starting from index 1
array.splice(1, 2, 6, 7); // (startIndex, countOfElementToDelete, ..elements to add)

console.log(array); // [1, 6, 7, 4, 5]

// |> 20. `slice`  : cutting a portion from array and returning it
// slice(start,end)
//slice(start);

const animals = ["ant", "bison", "camel", "duck", "elephant"];

console.log(animals.slice(2));
// Expected output: Array ["camel", "duck", "elephant"]

console.log(animals.slice(2, 4));
// Expected output: Array ["camel", "duck"]

console.log(animals.slice(1, 5));
// Expected output: Array ["bison", "camel", "duck", "elephant"]

console.log(animals.slice(-2));
// Expected output: Array ["duck", "elephant"]

console.log(animals.slice(2, -1));
// Expected output: Array ["camel", "duck"]

console.log(animals.slice());
// Expected output: Array ["ant", "bison", "camel", "duck", "elephant"]

//|> 21. `shift` : remove front element in array. Mutate the og array

const myFish = ["angel", "clown", "mandarin", "surgeon"];

console.log("myFish before:", myFish); // ['angel', 'clown', 'mandarin', 'surgeon']

const shifted = myFish.shift();

console.log("myFish after:", myFish); //['clown', 'mandarin', 'surgeon']

console.log("Removed this element:", shifted); // Removed this element: angel

// ----------------------------------------------------------------------------------
//|> 22. `unshift` :  adds elements at front of array. mutate the og array

const array22 = [1, 2, 3];

console.log(array1.unshift(4, 5)); //  5

console.log(array1); //  Array [4, 5, 1, 2, 3]

//|> 23. `reverse` : mutates the og array

const array23 = ["one", "two", "three"];
console.log("array1:", array1);
// Expected output: "array1:" Array ["one", "two", "three"]

const reversed = array1.reverse();
console.log("reversed:", reversed);
// Expected output: "reversed:" Array ["three", "two", "one"]

// Careful: reverse is destructive -- it changes the original array.
console.log("array1:", array23);
// Expected output: "array1:" Array ["three", "two", "one"]

// !NOTE : use `toReversed()`  if you dont want to mutate the og array. It return the new copy
