import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Locale;
import java.util.Optional;

public class Show {
  String show_id;
  String type;
  String title;
  String director; // nullable
  ArrayList<String> cast;
  String country; // nullable
  LocalDate date_added; // nullable
  int release_year;
  String rating; // nullable
  String duration;
  ArrayList<String> listed_in;

  /* Constructors */
  Show() {

  }

  Show(Show show) {

  }

  /* Set methods */
  void setId(String id) {
    show_id = id;
  }

  void setType(String type) {
    this.type = type;
  }

  void setTitle(String title) {
    this.title = title;
  }

  void setDirector(String director) {
    this.director = director;
  }

  void setCast(String[] cast) {
    this.cast = new ArrayList<String>(cast.length);

    this.cast.addAll(Arrays.asList(cast));
  }

  void setCast(ArrayList<String> cast) {
    this.cast = cast;
  }

  void setCountry(String country) {
    this.country = country;
  }

  void setDateAdded(LocalDate date_added) {
    this.date_added = date_added;
  }

  void setReleaseYear(int release_year) {
    this.release_year = release_year;
  }

  void setRating(String rating) {
    this.rating = rating;
  }

  void setDuration(String duration) {
    this.duration = duration;
  }

  void setListedIn(String[] listed_in) {
    this.listed_in = new ArrayList<String>(listed_in.length);

    this.listed_in.addAll(Arrays.asList(listed_in));
  }

  void setListedIn(ArrayList<String> listed_in) {
    this.listed_in = listed_in;
  }

  /* Get methods */
  String getId() {
    return show_id;
  }

  String getType() {
    return type;
  }

  String getTitle() {
    return title;
  }

  Optional<String> getDirector() {
    return Optional.ofNullable(director);
  }

  ArrayList<String> getCast() {
    return cast;
  }

  Optional<String> getCountry() {
    return Optional.ofNullable(country);
  }

  Optional<LocalDate> getDateAdded() {
    return Optional.ofNullable(date_added);
  }

  Optional<String> getDateAddedFormatted() {
    return getDateAdded()
            .map(dateAdded -> {
              DateTimeFormatter formatter = DateTimeFormatter.ofPattern("MMMM d, yyyy", Locale.ENGLISH);
              return dateAdded.format(formatter);
            });
  }

  int getReleaseYear() {
    return release_year;
  }

  Optional<String> getRating() {
    return Optional.ofNullable(rating);
  }

  String getDuration() {
    return duration;
  }

  ArrayList<String> getListedIn() {
    return listed_in;
  }

  /* Util methods */
  Show clone(Show showRef) {
    // sets all

    return showRef;
  }

  void print() {
    System.out.println("=> " + getId() +
            " ## " + getType() +
            " ## " + getTitle() +
            " ## " + getDirector().orElse("NaN") +
            " ## [" + String.join(", ", getCast()) + "]" +
            " ## " + getCountry().orElse("NaN") +
            " ## " + getDateAddedFormatted().orElse("NaN") +
            " ## " + getReleaseYear() +
            " ## " + getRating().orElse("NaN") +
            " ## " + getDuration() +
            " ## [" + String.join(", ", getListedIn()) + "]\n"
    );
  }

  Show read() {
    return this;
  }
}
