

class Navigation
{
    public:
        // a constructor!
        Navigation();

        // normal line following operation
        void line_follow(int default_speed, int exit_mode);
        // stops line following when sensed "x" distance away
        // void line_exit_distance();
        // pick encoder number of rotations
        // void line_exit_encoder();

        // pivot 90 degrees and check parallel with wall
        void pivot90(int direction);
        // use encoders to pivot 45 degrees
        void pivot45(int direction);
        // move set number of inches via encoder
        void move_encoder(int inches);
        // move until "x" distance from wall
        void move_sensor(int wall_dist, int sensor);



};


class WallFollow
{
    public:
        // a constructor!
        WallFollow();

        // pivot until side sensors equal (square up to smallest reading)
        void square_up();
        // stay parallel to wall at distance specified (forward and backwards)
        void follow_wall(int inches, int direction);
        // open from wall distance, works for forward and reverse
        void open(int wall_dist, int direction);
        // close in on wall distance, works for forward and reverse
        void close(int wall_dist, int direction);

}


// give inch amount, get encoder rotations
int encoder_conversion(int inches);

// give inch amount, get sensor number equivalent
int sensor_conversion(int inches);


