package observerVariant;

import java.util.Observable;
import java.util.Observer;

public class ClubMember implements Observer {
	private int memberNo;
	
	public ClubMember (int no) {
		this.memberNo = no;
	}

	@Override
	public void update(Observable arg0, Object arg1) {
		System.out.println("Member "+this.memberNo+" got message: "+arg1.toString());
	}

}
