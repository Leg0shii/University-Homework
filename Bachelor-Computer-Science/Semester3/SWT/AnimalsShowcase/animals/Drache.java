package animals;

public class Drache extends Tier{

	String schuppenfarbe;
	Schuppen schuppen;

	public Drache(int maxAlter, String schuppenfarbe) {

		super("Drache", maxAlter);
		this.schuppenfarbe = schuppenfarbe;
		this.schuppen = new Schuppen(1000, 50, "rund");

	}

	public String getSchuppenfarbe() {
		return schuppenfarbe;
	}

	public void setSchuppenfarbe(String schuppenfarbe) {
		this.schuppenfarbe = schuppenfarbe;
	}

	public Schuppen getSchuppen() {
		return schuppen;
	}

	public void setSchuppen(Schuppen schuppen) {
		this.schuppen = schuppen;
	}

}
