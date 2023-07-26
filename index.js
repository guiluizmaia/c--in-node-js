const { add } = require('./build/Release/add')

const { hello } = require('./build/Release/hello')

const { callback } = require('./build/Release/callback')

const CreateObject = require('./build/Release/createObject')
const CreateObject2 = require('./build/Release/createObject2')

console.log(hello())

console.log('adição ', add(1,  2, 1, 10))

callback((number1, number2) => {
    console.log(number1)
    console.log(number2)
})

const obj = CreateObject("Guilherme Luiz", "Maia", 23)
console.log(obj)

const obj2 = CreateObject2({name: "Guilherme Luiz", completeName: "Maia", age: 23})
console.log(obj2)