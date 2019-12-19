
## The code
```
const takeValidPoints = (dimensions: number, totalDegree: number): number[][] => {

  const appendAnotherDimension = (totalDegree: number, points: number[][]): number[][] => {
    let result: number[][] = []
    points.forEach(point => {
      // Append one more dimension
      for (let degree = 0; degree <= totalDegree; ++degree)
        result.push(point.concat([degree]))
    })
    return result
  }
  // Initialize the list of valid points to empty
  let points: number[][] = [[]]

  for (let dim = 1; dim <= dimensions; ++dim) {
    points = appendAnotherDimension(totalDegree, points)
  }

  return points.filter(point => point.reduce(add, 0) <= totalDegree)


}
```
## The algorithm

        How to append one more dimension to a space:
        
        For each point in the initial space
            For each possible value in those spaces
                Add that value to the point (incrementing the vector's dimensions)

        How to generate an exponents matrix:

        From empty until the space reach the desired dimensions
            Append uno more dimension to that space



## The rationale

Let's say we got

f(x,y) = Ax<sup>2</sup> + By<sup>2</sup> + Cxy + Dx + Ey + F

We can express that function this way

f(x,y) = Ax<sup>2</sup>y<sup>0</sup> + Bx<sup>0</sup>y<sup>2</sup> + Cx<sup>1</sup>y<sup>1</sup> + Dx<sup>1</sup>y<sup>0</sup> + Ex<sup>0</sup>y<sup>1</sup> + Fx<sup>0</sup>y<sup>0</sup>

And see the exponents involved.

And see the monomials. There are 6.

And see the total degree (2, the maximum of the sum of exponents in each monomial).

And see the dimensions of our space (2, two variables).

### Why 6 monomials?

If whe repeat the arrange of exponents e. g. f(x) = 5x<sup>1</sup>y<sup>1</sup> + 3x<sup>1</sup>y<sup>1</sup> always we can normalize the polynomial rewriting it as f(x) = 8x<sup>1</sup>y<sup>1</sup>. In the following considerations we will work with normalized polynomials.

For each dimension (x and y) we have 3 value choices for the exponent (0,1,2) therefore the number of all possible combinations is 9 (3<sup>2</sup>, permutations with repetition). They are:

```
    [0,0]
    [0,1]
    [0,2]
    [1,0]
    [1,1]
    [1,2]
    [2,0]
    [2,1]
    [2,2]

```
How we can generate this matrix?

One way is iterarively append a new dimension to a previous space, let's say generate a surface from a line or a volume from a surface, adding the new dimension points to each point in the initial space. In our case:

 - Start with the empty space (_really_ empty, _meta_ empty) like [[]].
 - Append the first dimension. And obtain [[0],[1],[2]].
 - Append the second dimension. And obtain [[0,0],[0,1],[0,2],[1,0],[1,1],[1,2],[2,0],[2,1],[2,2]].


### In summary

        How to append one more dimension to a space:
        
        For each point in the initial space
            For each possible value in those spaces
                Add that value to the point (incrementing the vector's dimensions)


### One more issue:
In the generated matrix there are invalid points:

```
    [0,0]
    [0,1]
    [0,2]
    [1,0]
    [1,1]
    [1,2] Ops!
    [2,0]
    [2,1] Ops!
    [2,2] Ops!

    The Ops! ones have a sum of exponents greater than the total degree!
```

The algorithm then removes the three invalid points...

...and because **that** we have 6 monomials out of 9 possible ones.



