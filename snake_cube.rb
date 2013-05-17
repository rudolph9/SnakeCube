class Cube
  attr :x
  attr :y
  attr :z
  def initialize x, y, z
    @x = x
    @y = y
    @z = z
  end
  def valid_snake? binary_string
    return false unless binary_string.length == binary_string.length
    valid_snake [[1,1,1,1]], binary_string
  end

  # @poistion_array contains position vectors e.g. [[x_0,y_0,z_0,d_0],[x_1,y_1,z_1,d_1]]
  def valid_snake position_array, binary_string
    return true if binary_string.empty?
    if binary_string[0] == '0'
      position_ = position_array
      position_.push (position_[-1])
      (position_[-1])[ ((position_[-1])[-1]).abs - 1] =+ ((position_[-1])[-1]).abs / (position_[-1])[-1]
      return false unless position_valid? position_[-1]
      self.valid_snake position_, binary_string[1..-1]
    else
      check_positions = [1,2,3]
      check_positions.delete_at ((position_array[-1])[-1]).abs - 1
      check_positions.concat check_positions.map { |i| -i}
      check_positions.each do |i|
        position_ = position_array
        position_.push( position_[-1])
        (position_[-1])[i.abs - 1] =+ i/i.abs
        (position_[-1])[-1] = i
        if position_valid? position_[-1]
          return true if self.valid_snake position_, binary_string[1..-1]
        end
      end
      return false
    end
  end
  # @position
  def position_valid? position
    true  
  end
end