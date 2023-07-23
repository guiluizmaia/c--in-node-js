const { add } = require('./build/Release/add')

const { hello } = require('./build/Release/hello')

const { callback } = require('./build/Release/callback')

console.log(hello())

console.log('adição ', add(1,  2, 1, 10))

callback((number1, number2) => {
    console.log(number1)
    console.log(number2)
})