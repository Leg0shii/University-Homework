package observerVariant;

public class Trainer extends ClubMember {
	private SportsClub club;

	public Trainer(int no, SportsClub sc) {
		super(no);
		this.club = sc;
	}
	
	public void cancelTraining (String msg) {
		club.setMessageBoard(msg);
	}

}
