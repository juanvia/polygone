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
 *
 * In this example n=2 (two-dimensional space) and also m=2 (max value in table)
 * then the valid points are (1,0), (0,0), (0,1), (2,0), (1,1) and (0,2)
 * because the digit sum of all of those is less or equal to 2
 * Note that in base-3 (m+1) the first nine numbers are 00, 01, 02, 10, 11, 12, 20, 21 and 22
 *
 * There is a bijection betwen A and the non-negative integers from
 * zero to (m+1)^n-1. Also A can be viewed as the set of those integers expressed in
 * base (m+1). The algorithm takes advantage of that.
 *
 * @param dim The number of dimensions the phase space A
 * @param deg Must be the max value the coordinates that the points of A can have
 * @returns The valid points in a `n`-dimensional and `n`ic phase space
 *
 */
var takeValidPoints = function (dim, deg) {
    // Initialize the list of valid points to empty
    var valids = [];
    // All the posibilities are taken into account
    var phaseSpaceCardinality = Math.pow((deg + 1), dim);
    // Visits the entire phase space searching for good points
    for (var ordinal = 0; ordinal < phaseSpaceCardinality; ++ordinal) {
        // the number expressed in base <deg+1>. This is the punch line!
        var point = transform(dim, deg + 1, ordinal);
        // the point tested (and adopted if its digits sum is adequate)
        if (point.reduce(ramda_1.add, 0) <= deg) {
            valids.push(point);
        }
    }
    return valids;
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
