use ncurses::WINDOW;

pub trait TAB {
    fn name(&self) -> &str;
    fn newwin(&self, w: WINDOW);
    fn refresh(&self, w: WINDOW);
    fn delwin(&self, w: WINDOW) -> bool;
}
