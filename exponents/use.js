import exponents from '.'
import chalk from 'chalk'
import { combinations } from 'mathjs'

// Initial setup...

const argv   = process.argv
const dim    = argv[2] && !isNaN(argv[2]) && parseInt(argv[2]) >  0 && parseInt(argv[2]) <  6 ? parseInt(argv[2]) : -1;
const deg    = argv[3] && !isNaN(argv[3]) && parseInt(argv[3]) > -1 && parseInt(argv[3]) < 10 ? parseInt(argv[3]) : -1;
if (dim === -1 || deg === -1) { 
  console.error("usage: ./use dim deg (dim:[1..5] & deg:[0..9])")
  process.exit(1)
}
console.log('\n'+chalk.green('✓') +`   Ah! you had brought very good input to me, dimensions: ${dim} and degree: ${deg}`) 

// Introduction

const n = dim
const m = combinations(dim+deg,deg)
console.log(`☛   Our quest is then to generate a ${m} x ${n} matrix. The destiny of the app rest in our trembling hands.`)
process.stdout.write(`✈   Dwarfs working in Moria... `)

// Process

const timeAtStart = new Date().getTime()
const matrix      = exponents(dim,deg)
const timeAtEnd   = new Date().getTime()

const diff        = timeAtEnd-timeAtStart

console.log(`done. In ${diff} miliseconds. Behold the golden matrix!\n`)
console.log(chalk.yellow(JSON.stringify(matrix)))

//Epilogue

console.log("")
if (matrix.length != m || matrix[0].length != n)
  console.log(chalk.red(`☹   Alas the matrix should be of ${m} rows and ${n} columns and is of ${matrix.length} rows and ${matrix[0].length} columns.`))
else
  console.log(chalk.green(`☺   Rejoice! The matrix should be of ${m} rows and ${n} columns and of that size it is indeed.`))
console.log("")

