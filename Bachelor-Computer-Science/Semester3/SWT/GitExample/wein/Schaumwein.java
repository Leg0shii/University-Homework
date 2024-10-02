package testworld.wein;

import testworld.wein.Wein;

public class Schaumwein extends Wein {

	String herstellung;

	public Schaumwein(Wein wein, String herstellung) {

		super(wein);
		this.herstellung = herstellung;

	}

	public Schaumwein(String name, String farbe, int alter, String herstellung) {

		super(name, farbe, alter);
		this.herstellung = herstellung;

	}

	public String getHerstellung() {
		return herstellung;
	}

	public void setHerstellung(String herstellung) {
		this.herstellung = herstellung;
	}
}
