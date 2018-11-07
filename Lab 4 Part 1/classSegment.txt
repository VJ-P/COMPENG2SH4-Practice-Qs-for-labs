package Main;
//represents segment lines; fields end1 and end2 represent the two endpoints of the segment line
//uses class Point defined previously
public class Segment {
    private Point end1;
    private Point end2;
    /*initializes end1 to a Point with coordinates x1, y1,
     and end2 to a Point with coordinates x2, y2 */
    public Segment(double x1, double x2, double y1,double y2){
        end1 = new Point(x1, y1);
        end2 = new Point(x2, y2);
    }
    /* no argument public constructor which initializes end1 to a
      Point with coordinates 0,0, and end2 to a Point with coordinates 1,1 */
    public Segment(){
        end1 = new Point(0, 0);
        end2 = new Point(1, 1);
    }
    
    public double getX1(){
        return end1.getX(); /* returns the field x of end1 */
    }
    public double getY1(){
        return end1.getY(); /* returns the field y of end1 */
    }
    public double getX2(){
        return end2.getX(); /* returns the field x of end2 */
    }
    public double getY2(){
        return end2.getY(); /* returns the field y of end2 */
    }
    public Point getEnd1(){
        Point p1 = new Point(getX1(), getY1());
        return p1; //returns a new point with the same coordinates as end1
    }
    public Point getEnd2(){
        Point p2 = new Point(getX2(), getY2());
        return p2; //returns a new point with the same coordinates as end2
    }
    public double length(){
        return end1.distanceTo(end2);     /* returns the length of this segment; it MUST use the method distanceTo() from class Point */
    }
    public boolean isLonger(Segment other){/* returns true if this Segment is longer than the other Segment and false otherwise;*/
        if (this.length() > other.length()){/* it MUST use method length() */
            return true;
        }
        else{
            return false;
        }
    }
    public Point midPoint(){                   //returns a new Point representing
        Point mid;                             //the middle of this Segment (it creates a new Point object and returns a reference to it)
        double xMid = (getX1() + getX2())/2;   //note the coordinates of the middle are the averages of the coordinates of the end points
        double yMid = (getY1() + getY2())/2;
        mid = new Point(xMid, yMid);
        return mid;
    }
    public boolean isEqual(Segment other){     //returns true if this segment is equal to the other segment;
        if(this.getX1()==other.getX1() && this.getY1()==other.getY1() && this.getX2()==other.getX2() && this.getY2()==other.getY2()){    //two segment lines are equal if they have the same end points, but not necessarily in the same order
            return true;
        }
        else if(this.getX1()==other.getX2() && this.getY1()==other.getY2() && this.getX2()==other.getX1() && this.getY2()==other.getY1()){
            return true;
        }
        else{
            return false;
        }
    }
    public static double longest(Segment[] arr){  // returns the length of the longest Segment in the array
        double Long = arr[0].length();            //it MUST use method isLonger()
        for(int i=1; i<arr.length; i++){
            if(arr[i].isLonger(arr[i-1]) == true){
                Long = arr[i].length();
            }
        }
        return Long;
    }
    public String toString(){ //returns a string representation of the segment line
        return("The is from point " + end1 + " to point " + end2);
    }
}//end class Segment
