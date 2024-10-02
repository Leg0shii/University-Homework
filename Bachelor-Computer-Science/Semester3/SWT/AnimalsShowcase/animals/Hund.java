package animals;

public class Hund extends Tier{

	String fellfarbe;

	public Hund(String name, int maxAlter, String fellfarbe) {

		super(name, maxAlter);
		this.fellfarbe = fellfarbe;

	}

	public String getFellfarbe() {
		return fellfarbe;
	}

	public void setFellfarbe(String fellfarbe) {
		this.fellfarbe = fellfarbe;
	}
}
