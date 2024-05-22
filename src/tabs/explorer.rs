use ncurses::{wrefresh, WINDOW};
use crate::tabs::TAB;

pub struct EXPLORER {
    path: String
}

impl EXPLORER {
    pub fn new() -> EXPLORER {
        EXPLORER { path: String::new() }
    }
}

impl TAB for EXPLORER {
    fn name(&self) -> &str {
        &self.path
    }
    fn newwin(&self, w: WINDOW) {
        wrefresh(w);
    }
    fn refresh(&self, w: WINDOW) {
        wrefresh(w);
    }
    fn delwin(&self, w: WINDOW) -> bool {
        true
    }
}
