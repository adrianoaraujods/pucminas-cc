
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Optional;
import java.util.Scanner;

class File {

    static String path = "/tmp/disneyplus.csv";

    public static String readLine(int index) {
        String line = null;

        if (index > 0) {
            try (BufferedReader reader = new BufferedReader(new FileReader(path))) {
                int i = 0;

                while (((line = reader.readLine()) != null) && i < index) {
                    i++;
                }
            } catch (IOException e) {
                // file doesn't exist
            }
        }

        return line;
    }

    public static ArrayList<String> readAllLines() {
        ArrayList<String> lines = null;

        try {
            lines = new ArrayList<>(Files.readAllLines(Paths.get(path)));
        } catch (IOException e) {
            // file doesn't exist
        }

        return lines;
    }

    public static ArrayList<String> readUntil(int index) {
        ArrayList<String> lines = new ArrayList<>();

        if (index > 0) {
            try (BufferedReader reader = new BufferedReader(new FileReader(path))) {
                String line;

                int i = 0;
                while (((line = reader.readLine()) != null) && i < index) {
                    lines.add(line);

                    i++;
                }
            } catch (IOException e) {
                // file doesn't exist
            }
        }

        return lines;
    }
}

class Show {

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

    static DateTimeFormatter formatter = DateTimeFormatter.ofPattern("MMMM d, yyyy");

    /* Constructors */
    public Show() {
    }

    public Show(String input) {
        Show.read(input);
    }

    /* Set methods */
    public void setId(String id) {
        show_id = id;
    }

    public void setType(String type) {
        this.type = type;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public void setDirector(String director) {
        this.director = director;
    }

    public void setCast(String[] cast) {
        if (cast != null && cast.length > 0 && !cast[0].isEmpty()) {
            this.cast = new ArrayList<>(cast.length);
            this.cast.addAll(Arrays.asList(cast));
            this.cast.sort(String::compareTo);
        } else {
            this.cast = new ArrayList<>(0);
        }
    }

    public void setCast(ArrayList<String> cast) {
        this.cast = cast;
    }

    public void setCountry(String country) {
        this.country = country;
    }

    public void setDateAdded(LocalDate date_added) {
        this.date_added = date_added;
    }

    public void setReleaseYear(int release_year) {
        this.release_year = release_year;
    }

    public void setRating(String rating) {
        this.rating = rating;
    }

    public void setDuration(String duration) {
        this.duration = duration;
    }

    public void setListedIn(String[] listed_in) {
        if (listed_in != null && listed_in.length > 0 && !listed_in[0].isEmpty()) {
            this.listed_in = new ArrayList<>(listed_in.length);
            this.listed_in.addAll(Arrays.asList(listed_in));
        } else {
            this.listed_in = new ArrayList<>(0);
        }
    }

    public void setListedIn(ArrayList<String> listed_in) {
        this.listed_in = listed_in;
    }

    /* Get methods */
    public String getId() {
        return show_id;
    }

    public String getType() {
        return type;
    }

    public String getTitle() {
        return title;
    }

    public Optional<String> getDirector() {
        return director != null && !director.isEmpty() ? Optional.of(director) : Optional.empty();
    }

    public ArrayList<String> getCast() {
        return cast;
    }

    public Optional<String> getCountry() {
        return country != null && !country.isEmpty() ? Optional.of(country) : Optional.empty();
    }

    public Optional<LocalDate> getDateAdded() {
        return Optional.ofNullable(date_added);
    }

    public Optional<String> getDateAddedFormatted() {
        return getDateAdded().map(dateAdded -> dateAdded.format(formatter));
    }

    public int getReleaseYear() {
        return release_year;
    }

    public Optional<String> getRating() {
        return Optional.ofNullable(rating);
    }

    public String getDuration() {
        return duration;
    }

    public ArrayList<String> getListedIn() {
        return listed_in;
    }

    /* Util methods */
    public Show cloneShow() {
        Show newShow = new Show();

        newShow.setId(this.show_id);
        newShow.setType(this.type);
        newShow.setTitle(this.title);
        newShow.setDirector(this.director);
        newShow.setCast(this.cast);
        newShow.setCountry(this.country);
        newShow.setDateAdded(this.date_added);
        newShow.setReleaseYear(this.release_year);
        newShow.setRating(this.rating);
        newShow.setDuration(this.duration);
        newShow.setListedIn(this.listed_in);

        return newShow;
    }

    public String toStr() {
        return ("=> " + getId()
                + " ## " + getTitle()
                + " ## " + getType()
                + " ## " + getDirector().orElse("NaN")
                + " ## [" + (getCast().isEmpty() ? "NaN" : String.join(", ", getCast())) + "]"
                + " ## " + getCountry().orElse("NaN")
                + " ## " + getDateAddedFormatted().orElse("NaN")
                + " ## " + getReleaseYear()
                + " ## " + getRating().orElse("NaN")
                + " ## " + getDuration()
                + " ## [" + (getListedIn().isEmpty() ? "NaN" : String.join(", ", getListedIn())) + "]"
                + " ##");
    }

    public void print() {
        System.out.println(this.toStr());
    }

    public static Show read(String input) {
        Show show = new Show();

        int startIndex = 0, endIndex;

        /* Show ID */
        endIndex = input.indexOf(',', startIndex);
        show.setId(input.substring(startIndex, endIndex));
        startIndex = endIndex + 1;

        /* Type */
        endIndex = input.indexOf(",", startIndex);
        show.setType(input.substring(startIndex, endIndex));
        startIndex = endIndex + 1;

        /* Title */
        if (input.charAt(startIndex) == '"') {
            startIndex++;
            endIndex = input.indexOf("\",", startIndex);

            show.setTitle(
                    input.substring(startIndex, endIndex).replace("\"", "")
            );
            startIndex = endIndex + 2;
        } else {
            endIndex = input.indexOf(",", startIndex);
            show.setTitle(input.substring(startIndex, endIndex));
            startIndex = endIndex + 1;
        }

        /* Director */
        if (input.charAt(startIndex) == '"') {
            startIndex++;
            endIndex = input.indexOf("\",", startIndex);

            show.setDirector(
                    input.substring(startIndex, endIndex).replace("\"", "")
            );
            startIndex = endIndex + 2;
        } else {
            endIndex = input.indexOf(",", startIndex);
            show.setDirector(input.substring(startIndex, endIndex));
            startIndex = endIndex + 1;
        }

        /* Cast */
        if (input.charAt(startIndex) == '"') {
            startIndex++;
            endIndex = input.indexOf("\",", startIndex);

            show.setCast(
                    input.substring(startIndex, endIndex).replace("\"", "").split(", ")
            );
            startIndex = endIndex + 2;
        } else {
            endIndex = input.indexOf(",", startIndex);
            show.setCast(
                    input.substring(startIndex, endIndex).replace("\"", "").split(", ")
            );
            startIndex = endIndex + 1;
        }

        /* Country */
        if (input.charAt(startIndex) == '"') {
            startIndex++;
            endIndex = input.indexOf("\",", startIndex);

            show.setCountry(input.substring(startIndex, endIndex));
            startIndex = endIndex + 2;
        } else {
            endIndex = input.indexOf(",", startIndex);
            show.setCountry(input.substring(startIndex, endIndex));
            startIndex = endIndex + 1;
        }

        /* Date Added */
        startIndex++;
        endIndex = input.indexOf("\",", startIndex);

        show.setDateAdded(LocalDate.parse(
                input.substring(startIndex, endIndex),
                formatter
        ));
        startIndex = endIndex + 2;

        /* Release Year */
        endIndex = input.indexOf(",", startIndex);
        show.setReleaseYear(Integer.parseInt(input.substring(startIndex, endIndex)));
        startIndex = endIndex + 1;

        /* Rating */
        endIndex = input.indexOf(",", startIndex);
        show.setRating(input.substring(startIndex, endIndex));
        startIndex = endIndex + 1;

        /* Duration */
        endIndex = input.indexOf(",", startIndex);
        show.setDuration(input.substring(startIndex, endIndex));
        startIndex = endIndex + 1;

        /* Listed In */
        if (input.charAt(startIndex) == '"') {
            startIndex++;
            endIndex = input.indexOf("\",", startIndex);
        } else {
            endIndex = input.indexOf(",", startIndex);
        }
        show.setListedIn(input.substring(startIndex, endIndex).split(", "));

        return show;
    }
}

public class SortingByMergesort {

    static Scanner scanner = new Scanner(System.in);
    static Show[] shows = new Show[512];
    static int n = 0;
    static int comparisons = 0;

    static void sort() {
        mergesort(0, n - 1);
    }

    static void mergesort(int left, int right) {
        if (left < right) {
            int half = (left + right) / 2;
            mergesort(left, half);
            mergesort(half + 1, right);
            interpolate(left, half, right);
        }
    }

    static void interpolate(int left, int half, int right) {
        int n1 = half - left + 1;
        int n2 = right - half;

        Show[] a1 = new Show[n1];
        Show[] a2 = new Show[n2];

        for (int i = 0; i < n1; i++) {
            a1[i] = shows[left + i];
        }

        for (int j = 0; j < n2; j++) {
            a2[j] = shows[half + 1 + j];
        }

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2) {
            comparisons++;

            if ((a1[i].getDuration()).compareTo(a2[j].getDuration()) <= 0) {
                shows[k++] = a1[i++];
            } else {
                shows[k++] = a2[j++];
            }
        }

        while (i < n1) {
            shows[k++] = a1[i++];
        }

        while (j < n2) {
            shows[k++] = a2[j++];
        }
    }

    static void untie() {
        for (int i = 1; i < n; i++) {
            Show temp = shows[i];
            int j = i - 1;

            while ((j >= 0)
                    && (shows[j].getDuration().equals(temp.getDuration()) && (shows[j].getTitle()).compareToIgnoreCase(temp.getTitle()
            ) > 0)) {
                comparisons++;
                shows[j + 1] = shows[j];
                j--;
            }
            shows[j + 1] = temp;
        }
    }

    public static void main(String[] args) {
        long start = System.currentTimeMillis();
        String line;

        while ((line = scanner.nextLine()).compareTo("FIM") != 0) {
            int index = Integer.parseInt(line.substring(1));
            shows[n] = Show.read(File.readLine(index));
            n++;
        }

        sort();
        untie();

        for (int i = 0; i < n; i++) {
            shows[i].print();
        }

        long end = System.currentTimeMillis();

        try (FileWriter writer = new FileWriter("matricula_mergesort.txt")) {
            writer.write("123456" + '\t' + (end - start) + '\t' + comparisons);
        } catch (IOException e) {
            //
        }
    }
}
