//FinalExam.java
public class FinalExam extends GradedAct{
// FinalExam: subclass, extends: keyword, GradedAct: superclass
// this subclass has inherited all the member fields and methods of the superclass GradedAct
	private int numQs; // numtypes have default value of zero
	private int pointsEach = 10;
	private int numMissed;
	public FinalExam (int q, int m) {
		numQs = q;
		numMissed = m;
		setScore ((q - m) * pointsEach); 
		}
	public double getPoints(){
		return (q-m) * pointsEach;
		}
	}// end of FinalExam subclass
	
	overriding a superclass field/method/constructor
	
	overrides - a subclass method (or field) with the same signature (same name, parameter types, and return type) as a superclass method (or field)
	
	ex.
	the getGrade() method of GradedAct inside the subclass...
	
	public char getGrade(){
		char LG;
		if (score <=90)
			LG = 'A';
		else if (score <=60)
			LG = 'C';
		else 
			LG = 'F';
		return LG;
		} // this overrides the superclass method
	
	// similarly for member fields (and constructors)
	- a subclass can only inherit from one superclass (using extends)
	- a child has only one mother class
		- but one superclass can have multiple subclasses
	- a subclass can also extends another subclass 
	- this keyword is a reference to the current instance of an object
	- you can invoke an overridden method, or field using the keyword super
		- inside of FinalExam constructor
			public FinalExam() {
				super(); // call the super class constructor
			)
			FinalExam e = new FinalExam();
				e.getGrade();
				e.super.getGrade();
	