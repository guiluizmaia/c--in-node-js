const { add } = require('./build/Release/add')
const { hello } = require('./build/Release/hello')


console.log(hello())
console.log('adição', add(1,  2, 1, 10))