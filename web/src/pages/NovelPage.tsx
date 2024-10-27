import React, { useState, useEffect, useCallback } from "react";

const containerStyle: React.CSSProperties = {
  justifyContent: "center",
  alignItems: "flex-start",
  minHeight: "100vh",
  width: "fit-content",
  margin: "0 auto",
  padding: "20px",
};

const verticalTextStyle: React.CSSProperties = {
  writingMode: "vertical-rl",
  textOrientation: "upright",
  whiteSpace: "pre-wrap",
  lineHeight: "2",
  maxHeight: "calc(100vh - 40px)",
  overflowY: "auto",
  textAlign: "left",
  fontSize: "2rem",
  fontWeight: "400",
  letterSpacing: "0.05em",
};

const NovelPage: React.FC = () => {
  const [fullText, setFullText] = useState<string>("");
  const [displayedText, setDisplayedText] = useState<string>("");
  const [currentIndex, setCurrentIndex] = useState<number>(0);
  const [isAnimating, setIsAnimating] = useState<boolean>(true);

  useEffect(() => {
    fetch("message.txt")
      .then((response) => response.text())
      .then((data) => {
        setFullText(data.replace(/<br\/>/g, "\n"));
      })
      .catch((error) => console.error("Error loading text file:", error));
  }, []);

  const animateText = useCallback(() => {
    if (currentIndex < fullText.length) {
      setDisplayedText((prev) => prev + fullText[currentIndex]);
      setCurrentIndex((prev) => prev + 1);
    } else {
      setIsAnimating(false);
    }
  }, [currentIndex, fullText]);

  useEffect(() => {
    if (fullText && isAnimating) {
      const timer = setTimeout(animateText, 50);
      return () => clearTimeout(timer);
    }
  }, [fullText, currentIndex, isAnimating, animateText]);

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
    <div style={containerStyle} onClick={toggleAnimation}>
      <div style={verticalTextStyle}>{displayedText}</div>
    </div>
  );
};

export default NovelPage;
