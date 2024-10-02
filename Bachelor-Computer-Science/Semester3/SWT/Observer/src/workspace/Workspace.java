package workspace;

import observer.IObserver;

public class Workspace implements IObserver {

	ActiveWorkspace activeWorkspace;

	public ActiveWorkspace getActiveWorkspace() {
		return activeWorkspace;
	}

	public void setActiveWorkspace(ActiveWorkspace activeWorkspace) {
		this.activeWorkspace = activeWorkspace;
	}

	@Override
	public void _update() {

		//update own screen

	}

	public void sync() {

		//updates active screen

	}

}
