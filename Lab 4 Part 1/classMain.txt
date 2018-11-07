package Main;

public class Lab4 {
    public static void main(String[] args) {
//TEST FOR CLASS STUDENT
        Student Kyle = new Student(7, "Kyle");
        Student Kawhi = new Student(2, "Kawhi");
        Student Danny = new Student(14, "Danny");
        Student[] StudentList = {Kyle, Kawhi, Danny};
        for(Student person : StudentList){
            System.out.println(person.getName() + " " + person.getId() + " " + person.getGrade());
        }
        Kyle.increaseGrade(-43);
        Kawhi.increaseGrade(500);
        Danny.increaseGrade(75);
        for(Student person : StudentList){
            System.out.println(person.getName() + " " + person.getId() + " " + person.getGrade());
        }
        if (Danny.gradeIsHigher(Kawhi) == true){
            System.out.println("Danny has a higher grade than Kawhi.");
        }
        if (Danny.gradeIsHigher(Kawhi) == false){
            System.out.println("Danny's grade is not higher than Kawhi.");
        }
        System.out.println("The highest grade is " + Student.highestGrade(StudentList));
        System.out.println(Kyle.toString());
        System.out.println(Kawhi.toString());
        System.out.println(Danny.toString());

//TEST FOR CLASS POINT
        Point p1 = new Point(2.0, 3.0);
        Point p2 = new Point();
        Point p3 = new Point(2.0, 4.7);
        Point p4 = new Point(0,0);
        Point[] PointList = {p1, p2, p3, p4};
        for(Point p : PointList){
            System.out.println(p.getX() + ", " + p.getY());
        }
        System.out.println("The distance between p1 and p3 is " + p1.distanceTo(p3));
        if(p2.isEqual(p1) == true){
            System.out.println("Point p1 is equal to p2");
        }
        else if (p2.isEqual(p1) == false){
            System.out.println("Point p1 is not equal to p2");
        }
        if(p2.isEqual(p4) == true){
            System.out.println("Point p1 is equal to p4");
        }
        else if (p2.isEqual(p4) == false){
            System.out.println("Point p1 is not equal to p4");
        }
        p2 = p3.symmetric();
        System.out.println("The symmetric of point p3 is " + p2.getX() + ", " + p2.getY());
        for(Point p : PointList){
            System.out.println(p.toString());
        }

//TEST FOR CLASS SEGMENT
        Segment s1 = new Segment(2,1,4,3);
        Segment s2 = new Segment(2,1,4,3);
        Segment s3 = new Segment(2,2,3,8);
        Segment s4 = new Segment();
        Segment s5 = new Segment(1,2,3,4);
        Segment sList[] = {s1, s2, s3, s4, s5};
        for(Segment s : sList){
            System.out.println("(" + s.getX1() + "," + s.getY1() + ") (" + s.getX2() + "," + s.getY2() + ")");
        }
        Point p5 = s2.getEnd1();
        Point p6 = s3.getEnd2();
        System.out.println("(" + p5.getX() + "," + p5.getY() + ") (" + p6.getX() + "," + p6.getY() + ")");
        System.out.println("The length of sengment 3 is " + s3.length());
        System.out.println("The length of sengment 2 is " + s2.length());
        System.out.println(s2.isLonger(s3));
        System.out.println(s1.isEqual(s2));
        System.out.println(s1.isEqual(s5));
        System.out.println("The longest segment in the list is " + Segment.longest(sList) + " units long.");
        System.out.println(s4.toString());

//TEST FOR CLASS TRIANGLE
        Triangle t1 = new Triangle(1,1,5,1,3,3);
        Triangle t2 = new Triangle(0,3,4,0);
        System.out.println("The perimeter of triangle 1 is " + t1.perimeter());
        System.out.println("The perimeter of triangle 2 is " + t2.perimeter());
        System.out.println("The centroid of triangle 1 is " + t1.centroid());
        System.out.println("The centroid of triangle 2 is " + t2.centroid());
        Triangle t3 = t2.deepCopy();
        System.out.println(t3.toString());
    }
}
