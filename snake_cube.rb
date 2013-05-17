class SnakeCube
  attr_reader :x
  attr_reader :y
  attr_reader :z
  def initialize x, y, z
    @x = x
    @y = y
    @z = z
  end
  def valid_snake? binary_string
    return false unless binary_string.length == (@x * @y * @z)
    (valid_snake [[1,1,1,1]], binary_string) or (valid_snake [[1,1,1,2]], binary_string) or (valid_snake [[1,1,1,3]], binary_string)
  end

  # @poistion_array contains position vectors e.g. [[x_0,y_0,z_0,d_0],[x_1,y_1,z_1,d_1]]
  def valid_snake position_array, binary_string
    if binary_string.length == 1 # only (cublets - 1) bits matter
      puts "Position Traveled: #{position_array}"
      return true 
    end 
    if binary_string[0] == '0'
      position_ = position_array.clone
      position_.push (position_[-1]).clone
      i = ((position_[-1])[-1])
      (position_[-1])[ i.abs - 1] = (position_[-1])[ i.abs - 1] + i.abs / i
      return false unless position_valid? position_
      self.valid_snake position_, binary_string[1..-1]
    else
      check_positions = [1,2,3]
      check_positions.delete_at ((position_array[-1])[-1]).abs - 1
      check_positions.concat check_positions.map { |i| -i}
      check_positions.each do |i|
        position_ = position_array.clone
        position_.push (position_[-1]).clone
        (position_[-1])[i.abs - 1] = (position_[-1])[i.abs - 1] + i/i.abs
        (position_[-1])[-1] = i
        if position_valid? position_
          return true if self.valid_snake position_, binary_string[1..-1]
        end
      end
      return false
    end
  end
  # @position
  def position_valid? position
    if position.uniq! == nil
      x = (position[-1])[0]
      y = (position[-1])[1]
      z = (position[-1])[2]

      if x > 0 and x <= @x and y > 0 and y <= @y and z > 0 and z <= @z
        return true
      end
    end
    false
  end
end