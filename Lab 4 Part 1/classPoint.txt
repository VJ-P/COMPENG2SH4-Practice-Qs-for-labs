package Main;
//represents points in the plane, in  asystem of cartesian coordinates; each point has the coordinates x and y
public class Point {
    private double x;
    private double y;
    //overloaded constructors
    public Point(double x1, double y1){
        x=x1; y=y1;
    }
    public Point(){
        x=0.0; y=0.0;
    }
    public double getX(){
        return x;
    }
    public double getY(){
        return y;
    }
    //returns the distance between this Point and the other Point
    public double distanceTo(Point other){
        return  Math.sqrt(Math.pow(x - other.x, 2) + Math.pow(y - other.y, 2));
    }
    //return true if this Point is equal to the other Point; two Points are equal if they have the same coordinates
    public boolean isEqual(Point other){
        if((x == other.x)&&(y == other.y)){
            return true;
        }
        else{
            return false;
        }
    }
    //returns the symmetric of this Point with respect to the origin (i.e., it creates a new point which is the
    //symmetric of this point with respect to the origin and returns a reference to the new point)
    public Point symmetric(){
        Point Psymm = new Point (-x, -y);
        return Psymm;
    }
    //returns a string representation of the object (example: The point has the coordinates x=3.5 and y=7.9)
    public String toString(){
        return ("(x=" + this.x + "," + " y=" + this.y + ")");
    }
}
