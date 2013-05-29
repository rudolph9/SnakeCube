_ = require 'underscore'



# A linked list
class exports.Position
  constructor: ( @x, @y, @z, @direction, @prev) ->

  move: (direction) ->
    @direction = _.clone direction
    norm = direction / Math.abs direction
    switch Math.abs direction
      when 1 then @x += norm
      when 2 then @y += norm
      when 3 then @z += norm


  clone: ->
    new Position @x, @y, @z, @direction, this

  valid: (snake_cube)->
    if ((0 < @x <= snake_cube.x) and (0 < @y <= snake_cube.y) and (0 < @z <= snake_cube.z))
      curr = this.prev
      while ( curr != null)
        return false if (@x == curr.x and @y == curr.y and @z == curr.z)
        curr = curr.prev
      return true
    else
      return false

class exports.SnakeCube
  constructor: ( @x, @y, @z) ->

  valid_snake: ( position, binary_string) ->
    if binary_string.length == 1
      return true

    if binary_string[0] == '0'
      position_ = position.clone()
      position_.move position_.direction
      if position_.valid this
        return @valid_snake position_, binary_string[1..-1]
      else 
        return false
    else
      check_positions = [1, 2, 3]
      check_positions.splice ((Math.abs position.direction) - 1), 1
      check_positions = check_positions.concat _.map check_positions, (i) -> -i
      if undefined != _.find check_positions, ((i) =>
        position_ = position.clone()
        position_.move i
        if position_.valid this
          if @valid_snake position_, binary_string[1..-1]
            return true)
        return true
      else
        return false