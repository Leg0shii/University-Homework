package workspace;

import observer.IObservable;
import observer.IObserver;

import java.util.ArrayList;

public class ActiveWorkspace implements IObservable {

	ArrayList<IObserver> observers;

	public ActiveWorkspace() {

		this.observers = new ArrayList<>();

	}

	@Override
	public void add(IObserver iObserver) {

		this.observers.add(iObserver);

	}

	@Override
	public void remove(IObserver iObserver) {

		this.observers.remove(iObserver);

	}

	@Override
	public void _notify() {

		for(IObserver iObserver : observers) {

			iObserver._update();

		}

	}

}
