chai = require 'chai'
expect = chai.expect
SnakeCube = require( '../src/snake_cube').SnakeCube
Position = require( '../src/snake_cube').Position
describe 'SnakeCube', ->
  it 'should return true for a valid snake', ->
    snake_cube = new SnakeCube 3, 3, 3
    start_position = new Position 1, 1, 1, 1, null
    expect( snake_cube.valid_snake start_position, '001110110111010111101010100').to.equal true
  it 'should return false for an invalid snake', ->
    snake_cube = new SnakeCube 3, 3, 3
    start_position = new Position 1, 1, 1, 1, null
    expect( snake_cube.valid_snake start_position, '000110110111010111101010100').to.equal false