package animals;

public class Schuppen {

	int anzahlSchuppen;
	int schuppenGroesse;
	String schuppenform;

	public Schuppen(int anzahlSchuppen, int schuppenGroesse, String schuppenform) {

		this.anzahlSchuppen = anzahlSchuppen;
		this.schuppenGroesse = schuppenGroesse;
		this.schuppenform = schuppenform;

	}

	public int getAnzahlSchuppen() {
		return anzahlSchuppen;
	}

	public void setAnzahlSchuppen(int anzahlSchuppen) {
		this.anzahlSchuppen = anzahlSchuppen;
	}

	public int getSchuppenGroesse() {
		return schuppenGroesse;
	}

	public void setSchuppenGroesse(int schuppenGroesse) {
		this.schuppenGroesse = schuppenGroesse;
	}

	public String getSchuppenform() {
		return schuppenform;
	}

	public void setSchuppenform(String schuppenform) {
		this.schuppenform = schuppenform;
	}

}
