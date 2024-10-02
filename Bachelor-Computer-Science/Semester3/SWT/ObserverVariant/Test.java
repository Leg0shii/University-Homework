package observerVariant;

public class Test {

	public static void main(String[] args) {
		SportsClub c = new SportsClub();
		ClubMember m1 = new ClubMember(1);
		Trainer t2 = new Trainer(2,c);
		c.addObserver(m1);
		c.addObserver(t2);
		
		t2.cancelTraining("Heute fällt Training aus.");
	}

}
