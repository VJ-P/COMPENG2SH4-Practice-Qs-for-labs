package Main;
//represents triangles; each triangle has three vertexes (vertex1, vertex2 and vertex3), which are Point objects
public class Triangle {
    //fields
    private Point Vertex1;
    private Point Vertex2;
    private Point Vertex3;
    //constructor - receives the coordinates of all three vertexes as arguments
    public Triangle(double x1, double y1, double x2, double y2, double x3, double y3){
        Vertex1 = new Point(x1, y1);
        Vertex2 = new Point(x2, y2);
        Vertex3 = new Point(x3, y3);
    }
    //another constructor - receives as arguments only the coordinates of two vertexes 
    //and sets the third one to be the origin
    public Triangle(double x1, double y1, double x2, double y2){
        Vertex1 = new Point(x1, y1);
        Vertex2 = new Point(x2, y2);
        Vertex3 = new Point(0,0);
    }
    //method to compute the perimeter of this triangle 
    //i.e., returns the sum of the lengths of all three sides of the triangle;
    //should use method distanceTo from class Point
    public double perimeter(){
        double sum;
        sum = Vertex1.distanceTo(Vertex2);
        sum += Vertex2.distanceTo(Vertex3);
        sum += Vertex3.distanceTo(Vertex1);
        return sum;
    }
    //method to return the centroid of the triangle
    public Point centroid(){
        double xCent = (Vertex1.getX() + Vertex2.getX() + Vertex3.getX())/3;
        double yCent = (Vertex1.getY() + Vertex2.getX() + Vertex3.getY())/3;
        Point Cent = new Point(xCent, yCent);
        return Cent;
    }
    //method to return a deep copy of this triangle; the deep copy should not share any piece of memory with this triangle
    public Triangle deepCopy(){
        Triangle copy = new Triangle(Vertex1.getX(), Vertex1.getY(), Vertex2.getX(), Vertex2.getY(), Vertex3.getX(), Vertex3.getY());
        return copy;
    }
    //method toString()
    public String toString(){
        return("The triangle has vertices " + Vertex1.toString() + "," + Vertex2.toString() + "," + Vertex3.toString());
    }
}
