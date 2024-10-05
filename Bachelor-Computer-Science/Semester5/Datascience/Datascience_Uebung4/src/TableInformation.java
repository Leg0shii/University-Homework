import java.util.ArrayList;

public class TableInformation {

	String name;
	ArrayList<ColumnInformation> columnInformation;
	
	public TableInformation(String name, ArrayList<ColumnInformation> columnInformation) {
		super();
		this.name = name;
		this.columnInformation = columnInformation;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public ArrayList<ColumnInformation> getColumnInformation() {
		return columnInformation;
	}

	public void setColumnInformation(ArrayList<ColumnInformation> columnInformation) {
		this.columnInformation = columnInformation;
	}
	
	@Override
	public String toString() {
		return name + columnInformation;
		
	}
}
