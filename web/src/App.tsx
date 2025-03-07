
import "./App.css";
import { Route, BrowserRouter as Router, Routes } from "react-router-dom";
import Card from "./components/Card";
import NovelPage from "./pages/NovelPage";

const App = () => {
  return (
    <Router>
      <Routes>
        <Route
          path="/"
          element={
            <Card
              image="https://picsum.photos/200/300"
              date="2024/10/26"
              text="透明ガールは夏のはじめに現れた。"
            />
          }
        />
        <Route path="/novel" element={<NovelPage />} />
      </Routes>
    </Router>
  );
};

export default App;
