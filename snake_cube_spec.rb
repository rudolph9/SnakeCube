require_relative './snake_cube.rb'

describe SnakeCube do 
  it "creates a valid cube object" do
    snake_cube = SnakeCube.new 3,3,3
    snake_cube.x.should( eq 3)
    snake_cube.y.should( eq 3)
    snake_cube.z.should( eq 3)
  end
  it "it validates a 2,2,2 cube correctly" do
    snake_cube = SnakeCube.new 2,2,2
    binary_string = '11111111'
    (snake_cube.valid_snake? binary_string).should eq(true)
  end
  it "it validates a 3,3,3 cube correctly" do
    snake_cube = SnakeCube.new 3,3,3
    binary_string = '001110110111010111101010100'
    (snake_cube.valid_snake? binary_string).should eq(true)
  end
end