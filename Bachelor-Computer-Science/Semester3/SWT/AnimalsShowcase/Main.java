import tiere.Drache;
import tiere.Hund;
import tiere.Tier;

public class Main {

	public static void main(String[] args) {

		Tier tier1 = new Tier("Tier1", 40);
		System.out.println(tier1.getName());

		Hund hund1 = new Hund("Bello",15, "braun");
		System.out.println("Fellfarbe: " + hund1.getFellfarbe());
		System.out.println("Name von Hund: " + hund1.getName());

		Drache drache1 = new Drache(5000, "gelb");

	}

}
