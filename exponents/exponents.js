"use strict";
exports.__esModule = true;
var ramda_1 = require("ramda");
/**
 * Helper for sorting the result
 */
var relevance = function (row) {
    return ramda_1.sum(row) * 1000000
        + ramda_1.reduce(Math.max, Number.MIN_VALUE)(row) * 1000
        + row.reduce(function (prev, cur, idx, arr) { return prev + Math.pow(2, (arr.length - idx)) * cur; }, 0);
};
/**
 * Criteria for sorting
 * @param a Fist element
 * @param b Second element
 */
var byRelevance = function (a, b) { return relevance(b) - relevance(a); };
/**
 * Delivers an array of given size of digits of given number expressed in given base
 *
 * @param size The digits number of the result (It'll be zero left padding if necessary)
 * @param base The base at wich the number will be expressed
 * @param value The input integer number
 */
var transform = function (size, base, value) { return ramda_1.pipe(ramda_1.concat(ramda_1.join('', ramda_1.repeat('0', size))), // ensure enough length for next step
ramda_1.takeLast(size), // the length must equals the value of the "size" variable
ramda_1.split(''), // transforms the number string representation to an array of chars
ramda_1.map(Number) // array of chars to array of numbers (one digit each)
)(value.toString(base)); }; // send to pipe the number in <base>ary form
/**
 * Returns the points in non-negative integer n-dimensional space (n < 6)
 * of size m  whose digts sum <= m (m < 10))
 * Believe it or not that's useful
 *
 * @remarks
 * Let A be a n-dimensional space of integers in the range (0...m)
 * Where n < 6 and m < 10 (i.e. the elements of V are digits)
 * The function below gives us a subset of A whose points p fullfill the contstraint:
 * "The sum of digits of p is less or equal to m"
 *
 * Example:
 *
 * ```
 * 2      (2,0)  (2,1)  (2,2)
 * 1      (1,0)  (1,1)  (1,2)
 * 0      (0,0)  (0,1)  (0,2)
 *
 *          0      1      2
 * ```
 * @param dim The number of dimensions the phase space A
 * @param deg Must be the max value the coordinates that the points of A can have
 * @returns The valid points in a `n`-dimensional and `n`ic phase space
 *
 */
// =====================================================================================
// FUNCTIONAL VERSION, MORE MESSY, A LOT SLOWER
// const takeValidPoints = (dimensions: number, totalDegree: number): number[][] => {
//   const allPossibleValues: number[] = Array(totalDegree + 1).fill(0).map((v, i) => i)
//   const appendAnotherDimension = (totalDegree: number, points: number[][]): number[][] =>
//     points.reduce((result: number[][], point: number[]) =>
//       result.concat(allPossibleValues.map(value => point.concat([value])))
//       , [])
//   // Initialize the list of valid points to empty
//   let points: number[][] = [[]]
//   for (let dim = 1; dim <= dimensions; ++dim) {
//     points = appendAnotherDimension(totalDegree, points)
//   }
//   return points.filter(point => point.reduce(add, 0) <= totalDegree)
// }
// =====================================================================================
var takeValidPoints = function (dimensions, totalDegree) {
    var appendAnotherDimension = function (totalDegree, points) {
        var result = [];
        points.forEach(function (point) {
            // Append one more dimension replacing each point with (totalDegree+1) new dimensions points
            for (var degree = 0; degree <= totalDegree; ++degree)
                result.push(point.concat([degree]));
        });
        return result;
    };
    // Initialize the list of valid points to empty
    var points = [[]];
    for (var dim = 1; dim <= dimensions; ++dim) {
        points = appendAnotherDimension(totalDegree, points);
    }
    return points.filter(function (point) { return point.reduce(ramda_1.add, 0) <= totalDegree; });
};
/**
 * Returns a matrix where each row is a exponents array for each term in the polynomial.
 * A 'exponents array' is a vector containing the powers at which the correspondent
 * independent variable must be raised
 *
 * @remarks
 *
 * This matrix is all you need in order to generate/calculate a Polynomial
 *
 * @param dimensions The number of dimensions the phase space A
 * @param degree Must be the max value the coordinates that the points of A can have
 * @returns The valid points in a `dimensions`-dimensional and `degree`ic phase space
 *
 */
exports.makeExponentsArray = function (dimensions, degree) {
    // Add zero degree case
    if (degree === 0) {
        return [ramda_1.repeat(0, dimensions)];
    }
    // Gathering the points whose sum of elements is less or equal to the given degree
    var stack = takeValidPoints(dimensions, degree);
    // On delivery be polite and give a neat, ordered list
    return ramda_1.sort(byRelevance, stack);
};
exports["default"] = exports.makeExponentsArray;
