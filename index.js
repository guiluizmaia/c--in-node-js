const { add } = require('./build/Release/add')

const { hello } = require('./build/Release/hello')

const { callback } = require('./build/Release/callback')

const ObjectFactory = require('./build/Release/createObject')
const ObjectFactory2 = require('./build/Release/createObject2')

const FunctionFactory = require('./build/Release/createFunction')

console.log(hello())

console.log('adição ', add(1,  2, 1, 10))

callback((number1, number2) => {
    console.log(number1)
    console.log(number2)
    console.log(number1 + number2)
})

const obj = ObjectFactory("Guilherme Luiz", "Maia", 23)
console.log(obj)

const obj2 = ObjectFactory2({name: "Guilherme Luiz", completeName: "Maia", age: 23})
console.log(obj2)

const func = FunctionFactory()
console.log(func())