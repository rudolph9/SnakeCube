require_relative './snake_cube.rb'

describe SnakeCube do 
  it "creates a valid cube object" do
    snake_cube = SnakeCube.new 3,3,3
    snake_cube.x.should( eq 3)
    snake_cube.y.should( eq 3)
    snake_cube.z.should( eq 3)
  end
  it "validates a 2,2,2 cube correctly" do
    snake_cube = SnakeCube.new 2,2,2
    binary_string = '11111111'
    (snake_cube.valid_snake? binary_string).should eq(true)
  end
  it "validates a valid 3,3,3 cube correctly" do
    snake_cube = SnakeCube.new 3,3,3
    binary_string = '001110110111010111101010100'
    (snake_cube.valid_snake? binary_string).should eq(true)
  end
  it "validates a valid 3,3,3 cube correctly" do
    snake_cube = SnakeCube.new 3,3,3
    binary_string = '010101111110101011010101010'
    (snake_cube.valid_snake? binary_string).should eq(true)
  end
  it "validates a valid 3,3,3 cube correctly" do
    snake_cube = SnakeCube.new 3,3,3
    binary_string = '010101111110101011010101010'.reverse
    (snake_cube.valid_snake? binary_string).should eq(true)
  end
  it "validates an invalid 3,3,3 cube correctly" do
    snake_cube = SnakeCube.new 3,3,3
    binary_string = '000101111110101011010101010'.reverse
    (snake_cube.valid_snake? binary_string).should eq(false)
  end
end

=begin
# A valid binary snake
1,1,1 => 0
1,1,2 => 0
1,1,3 => 1
1,2,3 => 0
1,3,3 => 1
1,3,2 => 0
1,3,1 => 1
1,2,1 => 1
1,2,2 => 1
2,2,2 => 1
2,3,1 => 1
2,3,3 => 1
2,2,3 => 0
2,1,3 => 1
2,1,2 => 0
2,1,1 => 1
2,2,1 => 0
2,3,1 => 1
3,3,1 => 1
3,3,2 => 0
3,3,3 => 1
3,2,3 => 0
3,1,3 => 1
3,1,2 => 0
3,1,1 => 1
3,2,1 => 0
3,2,2 => 1
=end