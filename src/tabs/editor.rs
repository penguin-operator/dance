use std::fs::File;
use std::io::{Read, Write};
use ncurses::{wrefresh, WINDOW};

use crate::tabs::TAB;

pub struct EDITOR {
    titie: String,
    file: Option<File>,
    data: String,
}

impl EDITOR {
    pub fn new() -> Self {
        EDITOR {
            titie: String::from("untitled"),
            file: None,
            data: String::new(),
        }
    }
}

impl TAB for EDITOR {
    fn name(&self) -> &str {
        &self.titie
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
