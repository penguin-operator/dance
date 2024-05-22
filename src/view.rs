use ncurses::{ delwin, mv, newwin, addstr, refresh, WINDOW};
use crate::TAB;

pub struct VIEW {
    tabs: Vec<(Box<dyn TAB>, WINDOW)>,
    pos: (i32, i32),
    size: (i32, i32),
}

impl VIEW {
    pub fn new(pos: (i32, i32), size: (i32, i32)) -> VIEW {
        VIEW {
            tabs: vec![],
            pos,
            size,
        }
    }
    pub fn refresh(&self) {
        mv(self.pos.0, self.pos.1);
        for tab in &self.tabs {
            addstr(tab.0.name()).unwrap();
            tab.0.refresh(tab.1);
        }
    }
    pub fn addtab<T: TAB + 'static>(&mut self, tab: T) {
        let last = self.tabs.len();
        self.tabs.push((Box::new(tab), newwin(
            self.size.0 - 1,
            self.size.1,
            self.pos.0 + 1,
            self.pos.1,
        )));
        self.tabs[last].0.newwin(self.tabs[last].1);
        refresh();
    }
    pub fn tabs(&self) -> usize {
        self.tabs.len()
    }
    pub fn tab(&self, i: usize) -> &(Box<dyn TAB>, WINDOW) {
        &self.tabs[i]
    }
    pub fn deltab(&mut self, i: usize) {
        if self.tabs[i].0.delwin(self.tabs[i].1) {
            delwin(self.tabs[i].1);
            self.tabs.remove(i);
        }
    }
}
