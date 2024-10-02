package observerVariant;

import java.util.Observable;

public class SportsClub extends Observable {
	private String messageBoard;

	public SportsClub() {
		this.messageBoard = "";
	}

	public String getMessageBoard() {
		return messageBoard;
	}

	public void setMessageBoard(String messageBoard) {
		this.messageBoard = messageBoard;
		this.setChanged();
		this.notifyObservers(getMessageBoard());
	}
}
