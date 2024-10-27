import React, { useState, useEffect, useCallback } from "react";

const containerStyle: React.CSSProperties = {
  display: "flex",
  justifyContent: "flex-end",
  width: "100%",
  height: "100vh",
  padding: "20px",
  boxSizing: "border-box",
  backgroundColor: "#fff",
  overflow: "auto",
};

const verticalTextStyle: React.CSSProperties = {
  writingMode: "vertical-rl",
  textOrientation: "upright",
  whiteSpace: "pre-wrap",
  lineHeight: "2",
  height: "calc(100vh - 40px)",
  textAlign: "left",
  fontSize: "2rem",
  fontWeight: "400",
  letterSpacing: "0.05em",
  paddingLeft: "20px",
};

const GlobalStyles: React.FC = () => (
  <style>{`
    body {
      margin: 0;
      padding: 0;
      overflow-x: hidden;
    }
    #root {
      width: 100%;
      height: 100vh;
      overflow: hidden;
    }
  `}</style>
);

const NovelPage: React.FC = () => {
  const [fullText, setFullText] = useState<string[]>([]);
  const [displayedText, setDisplayedText] = useState<string[]>([]);
  const [currentLine, setCurrentLine] = useState<number>(0);
  const [currentChar, setCurrentChar] = useState<number>(0);
  const [isAnimating, setIsAnimating] = useState<boolean>(true);

  useEffect(() => {
    fetch("../../public/message.txt")
      .then((response) => response.text())
      .then((data) => {
        const lines = data.split("<br/>");
        setFullText(lines);
        setDisplayedText(lines.map(() => ""));
      })
      .catch((error) => console.error("Error loading text file:", error));
  }, []);

  const animateText = useCallback(() => {
    if (currentLine < fullText.length) {
      if (currentChar < fullText[currentLine].length) {
        setDisplayedText((prev) =>
          prev.map((text, i) =>
            i === currentLine ? text + fullText[currentLine][currentChar] : text
          )
        );
        setCurrentChar((prev) => prev + 1);
      } else {
        setCurrentLine((prev) => prev + 1);
        setCurrentChar(0);
      }
    } else {
      setIsAnimating(false);
    }
  }, [currentLine, currentChar, fullText]);

  useEffect(() => {
    if (fullText.length > 0 && isAnimating) {
      const timer = setTimeout(animateText, 50);
      return () => clearTimeout(timer);
    }
  }, [fullText, currentLine, currentChar, isAnimating, animateText]);

  const toggleAnimation = () => {
    setIsAnimating(!isAnimating);
  };

  useEffect(() => {
    const handleKeyPress = (event: KeyboardEvent) => {
      if (event.code === "Space") {
        event.preventDefault();
        toggleAnimation();
      }
    };

    window.addEventListener("keydown", handleKeyPress);
    return () => window.removeEventListener("keydown", handleKeyPress);
  }, [isAnimating]);

  return (
    <>
      <GlobalStyles />
      <div style={containerStyle}>
        <div style={verticalTextStyle}>
          {displayedText.map((line, index) => (
            <React.Fragment key={index}>
              {line}
              <br />
            </React.Fragment>
          ))}
        </div>
      </div>
    </>
  );
};

export default NovelPage;
