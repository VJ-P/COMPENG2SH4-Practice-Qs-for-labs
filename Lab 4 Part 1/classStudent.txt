package Main;

public  class Student{
    private int id;
    private int grade;
    private String name;
    //constructor; initializes id to n, name to someName and grade to 0
    public Student (int n, String someName ){
        id = n;
        name = someName;
        grade = 0;
    }
    //sets the grade to mark if 0<=mark <=100; if mark is < 0, grade is set to 0; if mark > 100; grade is set to 100.
    public void setGrade( int mark ){
        if((mark >= 0)&&(mark<=100)){
            grade = mark;
        }
        else if(mark < 0){
            grade = 0;
        }
        else{
            grade = 100;
        }
    }
    //returns grade
    public int getGrade( ){
        return grade;
    }
    //returns ID
    public int getId( ){
        return id;
    }
    //returns the student's name
    public String getName(){
        return name;
    }
    // increases grade by adding to it the bonus, up to the limit of 100, and returns the new grade
    public int increaseGrade( int bonus ){
        if(((grade + bonus) <= 100)&&((grade + bonus) >= 0)){
            grade += bonus;
        }
        else if((grade + bonus) > 100) {
            grade = 100;
        }
        else if((grade + bonus) < 0 ){
            grade = 0;
        }
        return grade;
    }
    //compares the grades of this student and that student
    //and returns true if this student has higher grade, false otherwise
    public boolean gradeIsHigher(Student that){
        if(this.grade > that.grade){
            return true;
        }
        else{
            return false;
        }
    }
    //static method that returns the highest grade of the students in array a
    public static int highestGrade(Student[] a){
        int highG=0;
        for(Student i : a){
            if(i.grade > highG){
                highG = i.grade;
            }
        }
        return highG;
    }
    //returns a string representation of the object
    //(example: The student Robert Ford has the iD 6574 and the grade 100)
    public String toString(){
          return("The student " + name + " has the id " + id + " and the grade " + grade);
    }
} // end of class definition
