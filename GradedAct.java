// GradedAct.java
public class GradedAct {
	private double score;
	public void setScore (double s) {
		score = s;
		}
	public double getScore () {
		return score;
		}
	public char getGrade() {
		char LG;
		if (score >= 60)
			LG 'P';
		else
			LG = 'F';
		return LG;
		} // end of getGrade
	//somewhere else
	GradedAct grade = new GradedAct();
	grade.setScore(87);
	System.out.println("Your grade is " + grade.getGrade() + "!");
	